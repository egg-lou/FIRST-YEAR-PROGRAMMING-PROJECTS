import scrapy #
import pandas as pd
 
from ..items import ViceArticlesItem #To save the scraped content


class viceSpider (scrapy.Spider):
    name = 'vice_article_spider'  #Name of the scrapy spider 
    allowed_doomains = ['https://www.vice.com']  #The only allowed domain that the spider will scrape

    def start_requests (self):
        df = pd.read_csv('vice_links_10k.csv')  #reads the csv file

        urls = df['url']

        for url in urls:
            yield scrapy.Request(url = url, callback =self.parse)

    
    def parse (self, response):
        items = ViceArticlesItem()

        url = response.url
        items ['url'] = url

        title = response.css('.smart-header__hed--size-2::text').get()
        items ['title'] = title

        author = response.css('.contributor__meta a::text').getall()
        items ['author'] = author

        date = response.css('time::text').get()
        items ['date'] = date

        header = response.css ('.article__header__dek::text').get()
        items ['header'] = header

        content = response.css('p::text').getall()
        content_combined = " ".join(content)
        items ['content'] = content_combined

        yield items