#include "semantic_tablex.h"

// find operators
int SemanticTablex::find_not(string str){
  for(int i = 0; i<str.length(); i++){
    if(str[i] == '-') return i;
  }
  return -1;
}

int SemanticTablex::find_and(string str){
  for(int i = 0; i<str.length(); i++){
    if(str[i] == '.') return i;
  }
  return -1;
}

int SemanticTablex::find_or(string str){
  for(int i = 0; i<str.length(); i++){
    if(str[i] == '+') return i;
  }
  return -1;
}

int SemanticTablex::find_imply(string str){
  for(int i = 0; i<str.length(); i++){
    if(str[i] == '>') return i;
  }
  return -1;
}

int SemanticTablex::find_opening_bracket(string str){
  for(int i = 0; i<str.length(); i++){
    if(str[i] == '(') return i;
  }
  return -1;
}

int SemanticTablex::find_closing_bracket(string str){
  for(int i = 0; i<str.length(); i++){
    if(str[i] == ')') return i;
  }
  return -1;
}

// make operations
void SemanticTablex::negation(string proposition, bool truth_value){
  proposition = proposition.substr(1, proposition.length() - 2); // remove negation
  if(proposition[0] == "("){
    proposition = proposition.substr(1, proposition.length() - 3); // remove brackets
  }
  map<string, bool> temp_propositions;
  temp_propositions.insert(make_pair(proposition, !truth_value))
}

void SemanticTablex::conjunction(string proposition1, string proposition2, bool truth_value){
  map<string, bool> temp_propositions;
  if(truth_value){
    temp_propositions.insert(make_pair(proposition1, true)) && temp_propositions.insert(make_pair(proposition2, true));
  }else{
    temp_propositions.insert(make_pair(proposition1, false)) || temp_propositions.insert(make_pair(proposition2, false));
  }
}

void SemanticTablex::disjunction(string proposition1, string proposition2, bool truth_value){
  map<string, bool> temp_propositions;
  if(truth_value){
    temp_propositions.insert(make_pair(proposition1, true)) || temp_propositions.insert(make_pair(proposition2, true));
  }else{
    temp_propositions.insert(make_pair(proposition1, false)) && temp_propositions.insert(make_pair(proposition2, false));
  }
}


void SemanticTablex::implication(string proposition1, string proposition2, bool truth_value){
  proposition1 = "-(" + proposition1 + ")";
  disjunction(proposition1, proposition2, truth_value)
}

int SemanticTablex::comparator(string propostion, bool truth_value){
  int flag = 0;
  for(auto itr = atomic_propostions.begin(); itr != atomic_propostions.end(); itr++){
    if(itr->first == propostion){
      if(itr->second != truth_value){
        flag = 1;
      }else{
        atomic_propostions.insert(make_pair(propostion, truth_value));
      }
      break;
    }
  }
  return flag;
}

void SemanticTablex::interpreter(string proposition, bool truth_value){
  int len = proposition.length();
  string temp;
  int flag;

  // if the proposition is atomic proposition
  if(len == 1){
    flag = comparator(proposition, truth_value);
  }

  if(flag == 1){
    cout<<"this path create contradiction ";
    valid = true;
  }else{
    cout<<"this path doesn't create contradiction ";
    valid = false;
  }

  int i;
  i = find_imply(proposition);
  if(i != -1){
    string proposition1 = proposition.substr(0, i);
    string proposition2 = proposition.substr(i+1, len-i-1);
    implication(proposition1, proposition2, true);
  }
}

bool SemanticTablex::semantic_tableaux_calculator(vector<string> premise, vector<string> conclusion){
  vector<string> argument = premise;
  for(auto itr = conclusion.begin(); itr != conclusion.end(); itr++){
    string neg_conclusion = "-" + *itr;
    argument.push_back(neg_conclusion);
  }

  for(auto itr = argument.begin(); itr != argument.end(); itr++){
    interpreter(*itr, true);
  }
  return valid;
}
