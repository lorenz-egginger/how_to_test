#include <catch2/catch.hpp>

#include "behavior.h"

// It is much better to use separate tests to verify separate behaviors
SCENARIO("a user wants to buy an article", "[process_transaction_good]")
{
  User user{LOW_BALANCE_THRESHOLD + dollars(2)};

  GIVEN("a transaction that will take place")
  {
    Transaction transaction{"Pile of Beanie Babies", dollars(3)};

    WHEN("the user starts the transaction")
    {
      TransactionProcessor transaction_processor{};
      transaction_processor.processTransaction(user, transaction);

      THEN("The UI displays a notification")
      {
        CHECK(UI::getInstance().getText() == "You bought a Pile of Beanie Babies" );
      }

      AND_WHEN("the user's new balance is below the threshold")
      {
        REQUIRE(user.getBalance() < LOW_BALANCE_THRESHOLD);

        const auto email = user.getEmails();
        REQUIRE_FALSE(email.empty());

        THEN("an email is sent to the user informing him about the low balance")
        {
          CHECK(email.size() == 1);
          CHECK(email[0] == "Your balance is low");
        }
      }
    }
  }
}
