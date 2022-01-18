#ifndef LOGIC_H
#define LOGIC_H

#include <string>
#include <utility>

class Navigator
{
  std::string base_url_{};
  std::string current_url_{};

public:
  explicit Navigator(std::string  base_url) : base_url_(std::move(base_url)){};

  void goToPhotosPage() { current_url_ = base_url_ + "/u/0/photos"; };
  std::string getCurrentUrl() const { return current_url_; };
};

#endif
