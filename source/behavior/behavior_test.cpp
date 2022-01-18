#include <catch2/catch.hpp>

#include "behavior.h"

// It is much better to use separate tests to verify separate behaviors
SCENARIO("a user wants to buy an article", "[process_transaction_good]")
{

  GIVEN("a transaction that will take place")
  {
    User user{LOW_BALANCE_THRESHOLD + dollars(2)};
    Transaction transaction{"Pile of Beanie Babies", dollars(3)};

    WHEN("the user starts the transaction")
    {
      TransactionProcessor transaction_processor{};
      transaction_processor.processTransaction(user, transaction);

      THEN("The UI displays a notification")
      {
        REQUIRE(UI::getInstance().getText() == "You bought a Pile of Beanie Babies");
      }

      AND_WHEN("the user's new balance is below the threshold")
      {
        CHECK(user.getBalance() < LOW_BALANCE_THRESHOLD);

        THEN("an email is sent to the user informing him about the low balance")
        {
          REQUIRE(user.getEmails().size() == 1);
          REQUIRE(*user.getEmails().begin() == "Your balance is low");
        }
      }
    }
  }
}
