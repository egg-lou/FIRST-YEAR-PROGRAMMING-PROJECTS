import pandas as pd
from selenium import webdriver
import os
import time
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Add the Edge webdriver to the system path
os.environ['PATH'] += 'C:\edgedriver_win64'

# Open a new Edge browser window and navigate to the Vice Tech section
driver = webdriver.Edge() 
driver.get('https://www.vice.com/en/section/tech')

# Wait for 8 seconds for the page to load implicitly
driver.implicitly_wait(8)

# Set up an explicit wait with a timeout of 20 seconds
wait = WebDriverWait(driver, 20)

# Record the start time of the script
start_time = time.time()

# Get the initial height of the page
last_height = driver.execute_script('return document.body.scrollHeight')

# Scroll down the page and click on the "Load More" button until no more links are loaded
for _ in range(250):
    print("Scrolling down "+ str(_+1) + " times")
    driver.execute_script('window.scrollTo(0, document.body.scrollHeight);')
    
    # Try to locate the "Load More" button on the page and click it
    try:
        element = wait.until(EC.visibility_of_element_located((By.CLASS_NAME, "loading-lockup-infinite__button")))
        driver.execute_script("arguments[0].click();", element)
    
    # If the "Load More" button cannot be located, stop scrolling and print an error message
    except Exception as e:
        print(f"An error occurred: {e}")
        break 
    
    # Wait for 5 seconds for the page to load
    time.sleep(5)
    
    # Get the new height of the page
    new_height = driver.execute_script('return document.body.scrollHeight')
    
    # If the page height does not change after scrolling, stop scrolling
    if new_height == last_height:
        break
    last_height = new_height

# Scroll to the bottom of the page and wait for 3 seconds for the last links to load
driver.execute_script('window.scrollTo(0, document.body.scrollHeight);')
time.sleep(3)

# Record the end time of the scrolling process
elapsed_time = time.time() - start_time
print("Elapsed time after finishing scrolling: {:.2f} seconds".format(elapsed_time))

# Create an empty dictionary to store the scraped data
data = {'link': [], 'title': [], 'author': [], 'date': []}

# Find all the link divs on the page
divs = driver.find_elements("css selector", "li.feed__list__item.feed__list__item--card")

# Iterate over each link div and extract the link, title, author, and date
for div in divs:
    try:
        top = div.find_element("css selector", "div > div > h3 > a")
    except:
        top = ""
    
    if top != "":
        link = top.get_attribute('href')
        title = top.text
    else:
        link = ""
        title = ""

    author = div.find_elements("css selector", "div.vice-card-details__byline")
    date = div.find_elements("css selector", "time.vice-card-details__pub-date")
    
    author = author[0].text if author else ""
    date = date[0].text if date else ""

    data['author'].append(author)
    data['date'].append(date)
    data['link'].append(link)
    data['title'].append(title)

# Close the browser window
driver.quit()

# Convert the data dictionary to a Pandas DataFrame and save it as a CSV file
df = pd.DataFrame(data)
df.to_csv('tech_links.csv', index=False)
print(df.head())
print(df.shape)

# Record the end time of the script
elapsed_time2 = time.time() - start_time
print("Elapsed time after finishing scrolling: {:.2f} seconds".format(elapsed_time))
print("Elapsed time after finishing the whole process: {:.2f} seconds".format(elapsed_time2))