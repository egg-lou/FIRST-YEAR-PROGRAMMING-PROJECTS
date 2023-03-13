The vice website is an organizational website that contains different types of publications.
To be able to scrape this website for its news articles, Scrapy and the Pandas Python library was used.

Only contains one scrapy spider named vice_article_spider

Pre-Requisites
```
pip install scrapy 
pip install pandas
pip install scrapy-user-agents
```


There is only one spider used to scrape articles from the vice website

    1. vice_article_spider - To scrape the content of each article in the vice website


To run the article spider go to the terminal:
```
cd VICE_ARTICLES
scrapy crawl vice_article_spider -o filename .csv
```
