#pragma once
#include "Fragrance.h"
class Cart
{
    private:
		vector<const Fragrance*> fragrances;
    public:
        void add(const Fragrance* f);
        void remove(const string& fragranceName);
        void clear();
        double getTotalPrice() const;
        void view() const;
        const vector<const Fragrance*>& getItems() const;
};

