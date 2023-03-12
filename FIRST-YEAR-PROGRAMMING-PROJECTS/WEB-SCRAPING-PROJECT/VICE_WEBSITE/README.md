The vice website is an organizational website that contains different types of publications.
To be able to scrape this website for its news articles, Scrapy and the Pandas Python library was used.

Only contains one scrapy spider named vice_article_spider

To run the vice_article_spider:

1. pip install scrapy and pandas
```
pip install Scrapy
pip install Pandas
pip install scrapy-user-agents
```

2. Input these on the termninal
```
cd VICE_ARTICLES
scrapy crawl vice_article_spider -o filename.csv
```
