#include <catch2/catch.hpp>

#include "logic.h"

// simplifying the test by inlining the variable makes the problem obvious
SCENARIO("navigate to photos page without logic", "[navigate_to_photos_good]")
{

  GIVEN("a user wants to navigate from our homepage to the photos page")
  {
    Navigator nav{"http://plus.google.com/"};

    WHEN("the user clicks a link to our photos page")
    {
      nav.goToPhotosPage();

      THEN("the user gets navigated to the correct page")
      {
        CHECK(nav.getCurrentUrl() == "http://plus.google.com/u/0/photos"); // fails
      }
    }
  }
}
