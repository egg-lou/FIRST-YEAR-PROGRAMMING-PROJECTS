import scrapy
import pandas as pd
from ..items import UsipArticleItem


class articleSpider (scrapy.Spider):
    name = 'article_spider'   
    allowed_domains = ['https://www.usip.org']  
    

    def start_requests(self):
        df = pd.read_csv('usiparticle.csv')

        urls = df['url']
        for url in urls:
            yield scrapy.Request(url = url, callback = self.parse)

    
    def parse(self, response):
        
        items = UsipArticleItem()

        url = response.url

        items['url'] = url
 
        title = response.css('.page__header h1::text').get().strip()
        items ['title'] = title

        sub_header = response.css('.intro::text').get().strip()
        items ['sub_header'] = sub_header

        publication_type = response.xpath('//*[contains(concat( " ", @class, " " ), concat( " ", "publication-type", " " ))]//a[2]/text()').get()
        items ['publication_type'] = publication_type

        date = response.css('.intro+ .meta::text').get().strip()
        items ['date'] = date
        
        authors = response.css('.intro+ .meta a::text,').getall()
        items ['authors'] = authors

        text = response.css('.intro-wysiwyg p::text , .wysiwyg p::text , .wysiwyg h2::text, .wysiwyg h3::text').getall()
        items ['content'] = text
        
        yield items