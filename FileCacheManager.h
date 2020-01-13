//
// Created by yoel on 06/01/2020.
//

#ifndef MILESTONE2__FILECACHEMANAGER_H_
#define MILESTONE2__FILECACHEMANAGER_H_
#include <string>
#include "CacheManager.h"
#include <list>
#include "unordered_map"
#include "hash_fun.h"
using namespace std;
//template<typename Problem, typename Solution>
class FileCacheManager : public CacheManager<string, string> {
  class node {
   public:
    string key;
    string val;
  };

 private:
  unordered_map<string, string> map;
  hash<string> hashFunc;
  //typename list<node *>::iterator it;
  //list<node *> lst;
  //int size;
  int counter = 0;

 public:
/*  FileCacheManager(int siz) {
    //this->size = siz;
  }*/
  FileCacheManager() {

  }

  void insert(string str, string val) {
    WriteToFile(str, val);
    //lruAlgo(str, val);
  }

  //func of the lruAlgorithm
/*  void lruAlgo(string str, string val) {
    node *helper = new node();
    helper->key = str;
    helper->val = val;
    //case 1: there is place in the map and there is no string like str.
    if (counter < size) {
      if (map.count(str) <= 0) {
        lst.push_front(helper);
        map[str] = lst.begin();
        counter++;
      } else {
        //case 2: there is place in the map but str already have this key.
        delete (*(map[str]));
        lst.erase(map[str]);
        lst.push_front(helper);
        map[str] = lst.begin();

      }
    } else {
      //case 3: there is no place in map and the key is already in the map
      if (map.count(str) > 0) {
        delete (*(map[str]));
        lst.erase(map[str]);
        lst.push_front(helper);
        map[str] = lst.begin();
      }
        //case 4: there is no place in map and the key is not in the map.
      else {
        string temp = (*(--lst.end()))->key;
        map.erase(temp);
        delete (*(--lst.end()));
        lst.erase(--lst.end());
        lst.push_front(helper);
        map[str] = lst.begin();
      }
    }
  }*/
/*
  template<typename Func>
  void foreach(Func f) {
    for (it = lst.begin(); it != lst.end(); ++it) {
      f((*it)->val);
    }
  }*/

  string get(string str) {
    string val;
    string fileName = to_string(hashFunc(str));    //check if this key is in the cache
    if (map.count(fileName) > 0) {
      //it = map[str];
      //lruAlgo(fileName, (*it)->val);
      //return (*lst.begin())->val;
      //if it doesnt in the cache
      //} else {
      val = ReadFromFile(map[str]);
      //lruAlgo(str, val);

    } else return nullptr;
  }

//func that writing to file
  void WriteToFile(string str1, string ans) {

    fstream file;
    string fileName = to_string(hashFunc(str1));
    //file.open(fileName, ios::out | ios::binary);
    ofstream file1(fileName);
    if (!file) {
      throw "problem with file";
    }
    /*file.write((char *) &val1, sizeof(val1));*/
    file1 << ans;
    file1.close();
    map[str1] = fileName;
  }

//func that reading from file
  string ReadFromFile(string str1) {
    ifstream file;
    string fileName = to_string(hashFunc(str1));
    file.open(map[str1]);
    string line;
    char buffer[5000];
    getline(file, line);
    return line;
/*    string val1;
    fstream file;
    file.open(str1, ios::in | ios::binary);
    if (!file) {
      throw "bad file";
    }
    if (file.read((char *) &val1, sizeof(val1))) {
      file.
          close();
      return
          val1;
    } else {
      throw "bad file";
    }*/
  }

/*  ~FileCacheManager() {
    for (it = lst.begin(); it != lst.end(); ++it)
      delete *it;
  }*/
 public:

  bool isCacheHaveSol(string problemThatWeWantToCheck) override {
    string fileName = to_string(hashFunc(problemThatWeWantToCheck));
    return (map.count(problemThatWeWantToCheck) > 0);
  }
};

#endif //MILESTONE2__FILECACHEMANAGER_H_
