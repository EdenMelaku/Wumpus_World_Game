#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include <map>
#include "../KnowledgeBase/KB.h"
#include "../../utilities/DataStructures.h"

using namespace std;

class SemanticTablex{
  // tree structure
  struct node{
    struct node *left;
    struct node *right;
  };
  // struct *node sematic_tableaux_tree;

  map<string, bool> atomic_propostions;
  bool valid;

  // find operators
  int find_not(string str);
  int find_and(string str);
  int find_or(string str);
  int find_imply(string str);
  int find_opening_bracket(string str);
  int find_closing_bracket(string str);

  // make operations
  void negation(string proposition, bool truth_value);
  void conjunction(string proposition1, string proposition2, bool truth_value);
  void disjunction(string proposition1, string proposition2, bool truth_value);
  void implication(string proposition1, string proposition2, bool truth_value);

  void parser(string str);
  int comparator(string atomic_propostion, bool truth_value);
  void interpreter(string proposition, bool truth_value);

  bool semantic_tableaux_calculator(vector<string> premise, vector<string> conclusion);
};
