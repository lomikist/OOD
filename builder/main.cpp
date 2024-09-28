#include <string>
#include <iostream>
class House
{
private:
    std::string _wall;
    std::string _roof;
    bool _pool;
    int _door;
public:
    void set_pool(bool pool)
    {
        _pool = pool;
        std::cout << _pool << std::endl;
    };
    void set_wall(const std::string& wall)
    {
        _wall = wall;
        std::cout << _wall << std::endl;
    };
    void set_roof(const std::string& roof)
    {
        _roof = roof;
        std::cout << _roof << std::endl;
    };
    void set_door(int count)
    {
        _door = count;
        std::cout << _door << std::endl;
    }
};

class Builder
{
public:
    Builder()
    {
        _house = new House; 
    };
    virtual Builder& build_door() = 0;
    virtual Builder& build_roof() = 0;
    virtual Builder& build_wall() = 0;
    virtual Builder& build_pool() = 0;
    virtual void build() = 0;
    House* get_house()
    {
        return _house; 
    };
protected:
    House* _house;
};

class SimpleHouse : public Builder
{
    Builder& build_door() override 
    {
        _house->set_door(1);
        return *this;
    };
    Builder& build_roof() override 
    {
        _house->set_roof("panel");
        return *this;
    };
    Builder& build_wall() override 
    {
        _house->set_wall("brick");
        return *this;
    };
    Builder& build_pool() override 
    {
        _house->set_pool(false);
        return *this;
    };
public:
    void build() override 
    {
        build_wall().
        build_roof().
        build_door().
        build_pool();
    };
};
class LosPallos : public Builder
{

    Builder& build_door() override 
    { 
        _house->set_door(3);
        return *this; 
    };
    Builder& build_roof() override 
    { 
        _house->set_roof("wood");
        return *this; 
    };
    Builder& build_wall() override 
    { 
        _house->set_wall("tuff");
        return *this; 
    };
    Builder& build_pool() override 
    { 
        _house->set_pool(true);
        return *this; 
    };
public:
    void build() override 
    {
        build_wall().
        build_roof().
        build_door().
        build_pool();
    };
};

class Gustav
{
    Builder* _builder;
public:
    Gustav() = default;
    void set_builder(Builder* builder)
    {
        _builder = builder;
    };
    void make_house()
    {
        _builder->build();
    };
};

int main ()
{
    Gustav gustav;
    gustav.set_builder(new LosPallos);
    gustav.make_house();
    gustav.set_builder(new SimpleHouse);
    gustav.make_house();
    return 0;
};
