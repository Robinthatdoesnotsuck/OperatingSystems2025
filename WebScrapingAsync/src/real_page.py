from playwright.sync_api import sync_playwright

with sync_playwright() as p:
    browser = p.chromium.launch(headless=False)
    page = browser.new_page()
    page.goto("https://github.com/")
    print(page.title())
    page.fill("#hero_user_email", "placeholder@mail.com")
    submit_button = page.get_by_text("Sign up for GitHub")
    submit_button.first.click()
    print(page.title())
    dialog = page.get_attribute("")
    browser.close()
    