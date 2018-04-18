#include<iostream>
#include<string>
#include<vector>
#include<regex>

void  tokenize(std::string & text, std::vector<std::string>& text_prefix_tokens, std::vector<std::string>& text_suffix_tokens )
{
     std::string text_copy(text);
     int length =  text_copy.length();
     
     int i = 1;
     while( i <= length ) 
     {
          text_prefix_tokens.push_back(text_copy.substr(0, i));
          ++i;
     }   
    
     while( length-- ) 
     {
          text_suffix_tokens.push_back(text_copy.substr(length));        
     }        
}

     
    
std::string findHighestPattern(std::string & pre_text, std::string & post_text, std::string & text)
{
     std::vector<std::string> text_prefix_tokens;
     std::vector<std::string> text_suffix_tokens;
     tokenize(text, text_prefix_tokens, text_suffix_tokens);
  
     std::smatch matches;
     int post_text_score = 0;
    
     std::string post_result;
     for( auto &x : text_suffix_tokens)
     {
        std::regex pattern (x+"(.*)");      
        std::regex_match(post_text,matches,pattern);
          
        if(matches.size() > 0)
        {                                 
            int post_length = x.length();
            if(post_length > post_text_score)
            {
                post_text_score = post_length;
                post_result = x;
            }
        }
    }    
    int pre_text_score = 0;
    
    std::string pre_result;
    for( auto &x : text_prefix_tokens)
    {
        std::regex pattern ("(.*)"+x);
        std::regex_match(pre_text, matches, pattern);
          
        if(matches.size() > 0)
        {
            int pre_length = x.length();
            if(pre_length > pre_text_score)
            {
                pre_text_score = x.length();
                pre_result = x;
            }
        }
    }
    std::string result = pre_result + post_result;
    if(result.length() == 0)
    {          
        text_suffix_tokens.insert(std::end(text_suffix_tokens), std::begin(text_prefix_tokens), std::end(text_prefix_tokens));
        std::sort(std::begin(text_suffix_tokens),std::end(text_suffix_tokens));
       
        result = text_suffix_tokens.at(0);
    }     
    return result;
}


int main()
{ 
     std::string pre_text ("bruno");
     std::string text("nothing");
     std::string post_text("ingenious");
  
     //std::string pre_text ("b");
     //std::string text("ab");
     //std::string post_text("a");
     
     std::cout<< findHighestPattern(pre_text,post_text,text) <<"\n";
