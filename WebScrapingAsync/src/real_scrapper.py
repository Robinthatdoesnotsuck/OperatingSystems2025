from playwright.sync_api import sync_playwright

with sync_playwright() as p:
    browser = p.chromium.launch(headless=False)
    page = browser.new_page()
    page.goto("https://webscraper.io/test-sites/e-commerce/allinone")
    print(page.title())
    products = page.query_selector_all(".thumbnail")
    for product in products:
        title = product.query_selector(".title").text_content()
        price = product.query_selector(".price").text_content()
        print(f"{title}: {price}")

    browser.close()