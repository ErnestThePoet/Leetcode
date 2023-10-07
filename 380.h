#pragma once
#include <random>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet
{
private:
    unordered_map<int,int> indexes_;
    vector<int> values_;
    mt19937 mt_;

public:
    RandomizedSet():mt_(time(nullptr))
    {

    }

    bool insert(int val)
    {
        if (indexes_.find(val) != indexes_.cend())
        {
            return false;
        }

        values_.push_back(val);

        indexes_[val]=values_.size()-1;
        return true;
    }

    bool remove(int val)
    {
        if (indexes_.find(val) != indexes_.cend())
        {
            const int val_index = indexes_[val];
            values_[val_index] = values_[indexes_.size() - 1];
            indexes_[values_[val_index]] = val_index;
            values_.pop_back();
            indexes_.erase(val);

            return true;
        }

        return false;
    }

    int getRandom()
    {
        uniform_int_distribution<> distribution(0, indexes_.size()-1);
        return values_[distribution(mt_)];
    }
};