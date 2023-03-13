The USIP website is an organizational website that contains different types of publications from articles to special reports and etc.

Pre-Requisites 

```
pip install scrapy
pip install pandas
pip install scrapy-user-agents
```

Inside the USIP_WEBSITE Folder there are two folders, each has its own scrapy spider for a specific task.

    1. usip spider - To scrape the links of the articles for each page - USIP_SCRAPING Folder
    2. article spider - To scrape the contents of each article - USIP_ARTICLE Folder


To run the usip spider go to the terminal:
```
cd WEB-SCRAPING project
cd USIP_WEBSITE
cd USIP_SCRAPING
scrapy crawl usip -o filename.csv
```

To run the article spider go to the terminal:
```
cd WEB-SCRAPING project
cd USIP_WEBSITE
cd USIP_ARTICLE
scrapy crawl article_spider -o filename .csv
```