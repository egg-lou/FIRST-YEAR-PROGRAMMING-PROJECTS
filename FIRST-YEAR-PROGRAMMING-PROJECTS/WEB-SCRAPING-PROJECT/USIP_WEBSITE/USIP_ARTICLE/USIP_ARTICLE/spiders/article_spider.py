#importing scrapy, pandas, and UsipArticleItem
#Note: This setup only works on the publication type of article and will not work on other publication type
#Pandas is used to open the csv file created by the usip spider, make sure that the csv file is inside the folder USIP_ARTICLE
import scrapy
import pandas as pd
from ..items import UsipArticleItem


class articleSpider (scrapy.Spider):
    name = 'article_spider'   #spider name
    allowed_domains = ['https://www.usip.org']   #Although the csv file will only contain links from usip, it's still nice to have this
    

    def start_requests(self):
        df = pd.read_csv('usiparticle.csv') #Pandas reading the csv file

        urls = df['url']
        for url in urls:
            yield scrapy.Request(url = url, callback = self.parse)

    
    #Publication Type: Articles
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
        
        authors = response.css('.intro+ .meta a::text,').getall()  #It only works on a certain article, if the article clearly mentions its authors
        items ['authors'] = authors

        text = response.css('.intro-wysiwyg p::text , .wysiwyg p::text , .wysiwyg h2::text, .wysiwyg h3::text').getall()
        items ['content'] = text
        yield items
