#include <catch2/catch.hpp>

#include "behavior.h"

// This test verifies an entire method
TEST_CASE("testProcessTransaction", "[process_transaction_bad]")
{
  User user{LOW_BALANCE_THRESHOLD + dollars(2)};
  Transaction transaction{"Pile of Beanie Babies", dollars(3)};
  TransactionProcessor transaction_processor{};

  transaction_processor.processTransaction(user, transaction);
  REQUIRE(UI::getInstance().getText() == "You bought a Pile of Beanie Babies");
  REQUIRE(user.getEmails().size() == 1);
  REQUIRE(*user.getEmails().begin() == "Your balance is low");
}
