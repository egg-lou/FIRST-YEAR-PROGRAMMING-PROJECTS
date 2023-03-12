The vice website is an organizational website that contains different types of publications.
To be able to scrape this website for its news articles, Scrapy and the Pandas Python library was used.


    1. Setup up first a virutal environment to install Scrapy and Pandas

        python -m venv .\venv

    2. Activate the venv by typing this in the termina
        venv\Scripts\activate

    3. use pip to install SCrapy and Pandas
        pip install Scrapy 
        pip install Pandas


There is only one spider used to scrape articles from the vice website

    1. vice_article_spider - To scrape the content of each article in the vice website


To run the article spider go to the terminal:
    1. cd VICE_ARTICLES
    2. scrapy crawl vice_article_spider -o filename .csv
