#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <sstream>
#include <fstream>

std::string download(const std::string url, const std::string filename=""){

    std::ostringstream os;
    std::string html;

    try{

          os <<  curlpp::options::Url(url);

          html = os.str();

          if(filename != ""){
              // writting the downloaded data to a file.
              std::ofstream file;
              file.open(filename);
              file << html;
              file.close();
          }

    }catch(curlpp::RuntimeError& e){

        std::cout << e.what() << "\n";
        html ="";

    }catch(curlpp::LogicError& e){
        std::cout << e.what() << "\n";
        html = "";
    }

    return html;

}

#endif
