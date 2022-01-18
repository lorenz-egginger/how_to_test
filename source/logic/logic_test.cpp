#include <catch2/catch.hpp>

#include "logic.h"

// a test that actually looks correct
SCENARIO("navigate to photos page with logic", "[navigate_to_photos_bad]")
{

  GIVEN("a user wants to navigate from our homepage to the photos page")
  {
    std::string base_url = "http://plus.google.com/";
    Navigator nav{base_url};

    WHEN("the user clicks on a link to our photos page")
    {
      nav.goToPhotosPage();

      THEN("the user gets navigated to the correct page")
      {
        REQUIRE(nav.getCurrentUrl() == base_url + "/u/0/photos");
      }
    }
  }
}
