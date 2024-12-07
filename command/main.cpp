#include "icommand.hpp"
#include "client.hpp"
#include "add_command.hpp"
#include "remove_command.hpp"
#include <memory>
int main()
{
    std::shared_ptr<Icommand> com1 = std::make_shared<AddCommand>();
    std::shared_ptr<Icommand> com2 = std::make_shared<RemoveCommand>();
    
    Client clinet;
    clinet.set_command(com1);
    clinet.exec_command();
    clinet.set_command(com2);
    clinet.exec_command();
}
