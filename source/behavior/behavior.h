#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <string>
#include <utility>
#include <vector>

using dollars = int32_t;
static constexpr int32_t LOW_BALANCE_THRESHOLD = 10;

class UI
{
  std::string display_{};
  UI() = default;

public:
  UI(UI const&) = delete;
  void operator=(UI const&) = delete;
  ~UI() = default;

  static UI& getInstance() { static UI instance{}; return instance; }
  std::string getText() const { return display_; }

  void displayText(std::string text) { display_ = std::move(text); }
};

class User
{
  std::vector<std::string> emails_{};
  dollars balance_{};

public:
  explicit User(dollars balance) : balance_(balance){};

  void reduceBalance(dollars amount) { balance_ -= amount; }
  void addEmail(const std::string& text) { emails_.push_back(text); }

  std::vector<std::string> getEmails() const { return emails_; }
  dollars getBalance() const { return balance_; }
};

class Transaction
{
  std::string article_{};
  dollars price_{};

public:
  Transaction(std::string article, dollars price) : article_(std::move(article)), price_(price) {}

  std::string getArticle() const { return article_; }
  dollars getPrice() const { return price_; }
};

class TransactionProcessor
{

public:
  void processTransaction(User& user, Transaction& transaction)
  {
    UI::getInstance().displayText("You bought a " + transaction.getArticle());
    user.reduceBalance(transaction.getPrice());

    if (user.getBalance() < LOW_BALANCE_THRESHOLD)
    {
      user.addEmail("Your balance is low");
    }
  };
};

#endif
