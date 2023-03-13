The USIP website is an organizational website that contains different types of publications from articles to special reports and etc.

    1. Setup up first a virutal environment to install Scrapy and Pandas
        ```
        python -m venv .\venv
        ```
    2. Activate the venv by typing this in the terminal
        ```
        venv\Scripts\activate
        ```

    3. use pip to install SCrapy and Pandas
        ```
        pip install Scrapy 
        pip install Pandas
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
