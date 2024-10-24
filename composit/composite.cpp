#include <iostream>
#include <vector>

class IItem
{
public:
    virtual ~IItem() = default;
    virtual int GetPrice() const = 0; 
};

class AItem : public IItem
{
public:
    AItem(const std::string& name)
{
        this->name = name;
    }
    virtual void SetName(const std::string& name)
    {
        this->name = name;
    }
    virtual const std::string& GetName() const 
    {
        return name;
    } 
protected:
    std::string name;
};

class Item : public AItem
{
public:
    Item(int price, const std::string& name)
    : price(price), AItem(name)
    {};
    int GetPrice() const override 
    {
        return price;
    }
    void SetPrice(int price)
    {
        this->price = price;
    }

private: 
    int price;
};

class Group : public AItem  
{
public:
    Group(const std::string& name)
    : AItem(name)
    {};
 
    int GetPrice() const override 
    {
        int result = 0;
        for (auto&& i : items)
            result += i->GetPrice();
        return result;
    }
    void AddItem(AItem* item)
    {
        items.push_back(item);
    }
    
private:
    std::vector<AItem*> items;
};

int main()
{
    Group* group1 = new Group("group1");
    AItem* item1 = new Item(20, "item1");
    AItem* item2 = new Item(30, "item2");
    group1->AddItem(item1);
    group1->AddItem(item2);
    std::cout << item1->GetPrice();
    std::cout << item2->GetPrice();
    std::cout << group1->GetPrice();
};


