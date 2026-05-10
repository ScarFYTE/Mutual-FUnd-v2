#include <SFML/Graphics.hpp>
#include "User.h"
#include "Portfolio.h"
#include "MarketEngine.h"
#include "FileManager.h"
#include "AnalyticsManager.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({900u, 600u}), "Mutual Fund Investment Tracker");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cout << "Font file missing (arial.ttf). Place it in the project folder.\n";
        return 0;
    }

    User user("StudentInvestor", 10000);
    MarketEngine market;
    Portfolio portfolio;
    FileManager fileManager;
    AnalyticsManager analytics;

    fileManager.loadData(user, portfolio);

    sf::Text title(font, "Mutual Fund Investment Tracker", 24);
    title.setFillColor(sf::Color::Black);
    title.setPosition({20.f, 20.f});

    sf::Text info(font, "", 16);
    info.setFillColor(sf::Color::Black);
    info.setPosition({20.f, 70.f});

    sf::Text fundsText(font, "", 16);
    fundsText.setFillColor(sf::Color::Black);
    fundsText.setPosition({20.f, 130.f});

    sf::Text portfolioText(font, "", 16);
    portfolioText.setFillColor(sf::Color::Black);
    portfolioText.setPosition({20.f, 340.f});

    sf::RectangleShape buyBtn(sf::Vector2f(120.f, 35.f));
    buyBtn.setFillColor(sf::Color(100, 200, 120));
    buyBtn.setPosition({700.f, 150.f});

    sf::RectangleShape sellBtn(sf::Vector2f(120.f, 35.f));
    sellBtn.setFillColor(sf::Color(200, 100, 100));
    sellBtn.setPosition({700.f, 200.f});

    sf::Text buyText(font, "Buy 10 Units", 14);
    buyText.setFillColor(sf::Color::Black);
    buyText.setPosition({710.f, 157.f});

    sf::Text sellText(font, "Sell 10 Units", 14);
    sellText.setFillColor(sf::Color::Black);
    sellText.setPosition({710.f, 207.f});

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                fileManager.saveData(user, portfolio);
                window.close();
            }

            if (const auto *mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mouse(static_cast<float>(mouseEvent->position.x),
                                  static_cast<float>(mouseEvent->position.y));

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
