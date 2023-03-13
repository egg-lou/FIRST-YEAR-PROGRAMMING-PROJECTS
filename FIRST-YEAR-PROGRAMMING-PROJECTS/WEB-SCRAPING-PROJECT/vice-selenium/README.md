# Webscraping Vice Article Links with Python & Selenium
This Python script uses the Selenium WebDriver to scrape links, titles, authors, and dates from the Vice Tech section and saves the data as a CSV file.

## Prerequisites
- Python 3.x
- Pandas library
- Selenium WebDriver for Edge

The script will scroll through the page and click on the "Load More" button until no more links are loaded. Once all the links are loaded, the script will scrape the links, titles, authors, and dates and save the data as a CSV file.

# Merging all data
The merge_csv_files.ipynb was used to merge multiple CSV files into a single DataFrame, checks for uncleaned data, cleans the date column and adds a new column 'type'