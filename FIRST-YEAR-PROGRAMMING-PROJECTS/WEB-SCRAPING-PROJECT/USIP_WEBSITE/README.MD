The USIP website is an organizational website that contains different types of publications from articles to special reports and etc.
To be able to scrape this website for its news articles, Scrapy and the Pandas  Python library was used.

Contains two scrapy spider inside the two folders
```
usip - spider to scrape the links of the articles for each page - USIP_SCRAPING Folder
article_spider - spider to scrape the contents of an article from USIP article links scraped by usip spider - USIP_ARTICLE Folder
```

To run scrape the usip website for links and content:

1. pip install scrapy and pandas
```
pip install Scrapy
pip install Pandas
pip install scrapy-user-agents
```

2. To run "usip" scrapy spider
```
cd WEB-SCRAPING project
cd USIP_WEBSITE
cd USIP_SCRAPING
scrapy crawl usip -o filename.csv
```

3. To run "article_spider" scrapy spider
```
cd WEB-SCRAPING project
cd USIP_WEBSITE
cd USIP_ARTICLE
scrapy crawl article_spider -o filename .csv
```
