// Copyright 2019-2021 Lawrence Livermore National Security, LLC and other YGM
// Project Developers. See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: MIT

#undef NDEBUG

#include <filesystem>
#include <ygm/comm.hpp>
#include <ygm/io/ndjson_parser.hpp>

int main(int argc, char** argv) {
  ygm::comm world(&argc, &argv);

  size_t              local_count{0};
  ygm::io::ndjson_parser jsonp(world, std::vector<std::string>{"data/3.ndjson"});
  jsonp.for_all([&world, &local_count](const auto& json) {
    //world.cout(json.as_object());
    std::cout << json << std::endl;
  });

  world.barrier();
  
  return 0;
}
