# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class UsipArticleItem(scrapy.Item):
    # define the fields for your item here like:
    """
    #Publication Type: Article
    title = scrapy.Field()
    sub_header = scrapy.Field()
    publication_type= scrapy.Field()
    date = scrapy.Field()
    authors = scrapy.Field()
    content = scrapy.Field()
    url = scrapy.Field()
    """

    #Publication Type: Special Report
    title = scrapy.Field()
    publication_type= scrapy.Field()
    date = scrapy.Field()
    authors = scrapy.Field()
    header_content = scrapy.Field()
    summary = scrapy.Field()
    url = scrapy.Field()


