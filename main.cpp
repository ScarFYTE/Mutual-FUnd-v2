#include <SFML/Graphics.hpp>
#include "User.h"
#include "Portfolio.h"
#include "MarketEngine.h"
#include "FileManager.h"
#include "AnalyticsManager.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 600), "Mutual Fund Investment Tracker");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Font file missing (arial.ttf). Place it in the project folder.\n";
        return 0;
    }

    User user("StudentInvestor", 10000);
    MarketEngine market;
    Portfolio portfolio;
    FileManager fileManager;
    AnalyticsManager analytics;

    fileManager.loadData(user, portfolio);

    sf::Text title("Mutual Fund Investment Tracker", font, 24);
    title.setPosition(20, 20);

    sf::Text info("", font, 16);
    info.setPosition(20, 70);

    sf::Text fundsText("", font, 16);
    fundsText.setPosition(20, 130);

    sf::Text portfolioText("", font, 16);
    portfolioText.setPosition(20, 340);

    sf::RectangleShape buyBtn(sf::Vector2f(120, 35));
    buyBtn.setFillColor(sf::Color(100, 200, 120));
    buyBtn.setPosition(700, 150);

    sf::RectangleShape sellBtn(sf::Vector2f(120, 35));
    sellBtn.setFillColor(sf::Color(200, 100, 100));
    sellBtn.setPosition(700, 200);

    sf::Text buyText("Buy 10 Units", font, 14);
    buyText.setPosition(710, 157);

    sf::Text sellText("Sell 10 Units", font, 14);
    sellText.setPosition(710, 207);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                fileManager.saveData(user, portfolio);
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);

                if (buyBtn.getGlobalBounds().contains(mouse)) {
                    portfolio.buyUnits(user, market.getFunds()[0], 10);
                }
                if (sellBtn.getGlobalBounds().contains(mouse)) {
                    portfolio.sellUnits(user, market.getFunds()[0], 10);
                }
            }
        }

        market.updateNAVs();

        info.setString("User: " + user.getName() + " | Balance: Rs. " + std::to_string((int)user.getBalance()));
        fundsText.setString("Available Funds:\n" + market.getFundsDisplay());
        portfolioText.setString("Portfolio:\n" + portfolio.getHoldingsDisplay() +
                                "\n\nAnalytics:\n" + analytics.generateReport(portfolio));

        window.clear(sf::Color(245, 245, 245));
        window.draw(title);
        window.draw(info);
        window.draw(fundsText);
        window.draw(portfolioText);
        window.draw(buyBtn);
        window.draw(sellBtn);
        window.draw(buyText);
        window.draw(sellText);
        window.display();
    }

    return 0;
}
