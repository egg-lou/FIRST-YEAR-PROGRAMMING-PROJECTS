#importing scrapy and the UsipScrapingItem to save the output in a csv/json file
#Note: This spider will only get the links for the publication type article in the website
import scrapy

from ..items import UsipScrapingItem

class UsipSpider (scrapy.Spider):
    name = 'usip'     #name of the spider
    page_number = 1   #for the page of the website after the start_urls

    #Input here the link of the page of the website to scrape it for the links of the article
    start_urls = [
        'https://www.usip.org/publications?page=0'
    ]

    def parse (self, response):
        
        items = UsipScrapingItem()  #To store the collected links in a csv/json file

        all_articles = response.css('article.summary')  #The tag that contains the links for the articles

        for article in all_articles:
            links = article.css('.summary__heading a').xpath('@href').get()  #To get the link from the tag
            
            items ['url'] = "https://www.usip.org" + links   #Storing the links into the items file
            yield items

        #To go to the next page
        next_page = 'https://www.usip.org/publications?page=' + str(UsipSpider.page_number) + ''
        if UsipSpider.page_number < 511: 
            UsipSpider.page_number += 1
            yield response.follow(next_page, callback = self.parse)
