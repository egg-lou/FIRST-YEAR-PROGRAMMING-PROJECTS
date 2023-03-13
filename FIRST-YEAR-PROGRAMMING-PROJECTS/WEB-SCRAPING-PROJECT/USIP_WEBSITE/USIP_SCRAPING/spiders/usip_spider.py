import scrapy

from ..items import UsipScrapingItem

class UsipSpider (scrapy.Spider):
    name = 'usip'     
    page_number = 1   

    
    start_urls = [
        'https://www.usip.org/publications?page=0'
    ]

    def parse (self, response):
        
        items = UsipScrapingItem()  

        all_articles = response.css('article.summary')  

        for article in all_articles:
            links = article.css('.summary__heading a').xpath('@href').get()  
            
            items ['url'] = "https://www.usip.org" + links  
            yield items


        next_page = 'https://www.usip.org/publications?page=' + str(UsipSpider.page_number) + ''
        if UsipSpider.page_number < 511: 
            UsipSpider.page_number += 1
            yield response.follow(next_page, callback = self.parse)
