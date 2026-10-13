#pragma once

#include <string>

// The plain-text files that act as this program's "database" live in the
// data/ folder at the project root.
//
// These helpers resolve a bare file name such as "Clients.txt" to the place
// the file actually lives, so the program behaves the same whether it is
// launched from the project root (files in data/) or from a folder where the
// data files sit next to the executable - which is how older copies of this
// project were laid out.
namespace data {

// Returns the path to use for a data file.
//
// Lookup order:
//   1. data/<fileName>   - preferred, used by the current layout
//   2. <fileName>        - legacy layout: data files beside the executable
//   3. data/<fileName>   - nothing exists yet, so this is a file the program
//                          is about to create; data/ is created if missing
std::string path(const std::string& fileName);

}  // namespace data
