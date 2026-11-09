//
// Created by mikae on 22.09.2026.
//

#include"TMovieNode.h"
using namespace std;

//constructor initialises the movie pointer and node pointers
TMovieNode::TMovieNode(TMovie* movie) : data(movie), next(nullptr), previous(nullptr) {}

//destructor deletes the TMovie object stored by the node
TMovieNode::~TMovieNode() {delete data;}

//Getter methods to access the next and prev pointers
TMovieNode* TMovieNode::GetNext(){return next;}
TMovieNode* TMovieNode::GetPrevious(){return previous;}

//setters methods to set new pointers
void TMovieNode::SetNext(TMovieNode* node){next = node;}
void TMovieNode::SetPrevious(TMovieNode* node){previous = node;}

//getter to retrieve the TMovie object stored in this node
TMovie* TMovieNode::GetData() {return data;}