#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include "NotinOOP.h"
#include "IComand.h"
#include "AddToBalanceCommand.h"
#include "AddToCartCommand.h"
#include "RemoveFromCartCommand.h"
#include "ViewCartCommand.h"
#include "CheckoutCommand.h"
#include "ViewBoughtCommand.h"
#include "ViewPurchasesCommand.h"
#include "CancelPurchaseCommand.h"
#include "RecommendCommand.h"
#include "MakeReviewCommand.h"
#include "CreateFragranceCommand.h"
#include "AddQuantityCommand.h"
#include "DeliverCommand.h"
#include "RemoveReviewCommand.h"
#include "BlockUserCommand.h"
#include "AddToWishlistCommand.h"
#include "RemoveFromWishlistCommand.h"

using namespace std;

int main()
{
    shared_ptr<NotinOOP> shopSystem = make_shared<NotinOOP>();

    shopSystem->registerUser("admin", "1234", "admin", shopSystem);

    cout << "=== ДОБРЕ ДОШЛИ В СИСТЕМАТА NotinOOP ===\n";
    cout << "Въведете 'help' за списък с команди или 'exit' за изход.\n";

    string commandName;

    while (true)
    {
        cout << "\n> ";
        cin >> commandName;

        if (commandName == "exit")
        {
            cout << "Довиждане!\n";
            break;
        }

        try
        {
            unique_ptr<ICommand> command = nullptr;

            if (commandName == "register")
            {
                string username, password, role;
                cin >> username >> password >> role;
                shopSystem->registerUser(username, password, role, shopSystem);
                continue;
            }
            else if (commandName == "login")
            {
                string username, password;
                cin >> username >> password;
                shopSystem->login(username, password);
                cout << "Успешно влизане като " << username << "!\n";
                continue;
            }
            else if (commandName == "logout")
            {
                shopSystem->logout();
                cout << "Успешно излизане от профила.\n";
                continue;
            }
            else if (commandName == "help")
            {
                User* loggedInUser = shopSystem->getCurrentUser();
                if (loggedInUser != nullptr)
                {
                    loggedInUser->help();
                }
                continue;
            }
            else if (commandName == "add-to-balance")
            {
                double amount;
                cin >> amount;
                command = make_unique<AddToBalanceCommand>(shopSystem, amount);
            }
            else if (commandName == "add-to-cart")
            {
                string fragranceName;
                cin >> fragranceName;
                command = make_unique<AddToCartCommand>(shopSystem, fragranceName);
            }
            else if (commandName == "remove-from-cart")
            {
                string fragranceName;
                cin >> fragranceName;
                command = make_unique<RemoveFromCartCommand>(shopSystem, fragranceName);
            }
            else if (commandName == "view-cart")
            {
                command = make_unique<ViewCartCommand>(shopSystem);
            }
            else if (commandName == "checkout")
            {
                command = make_unique<CheckoutCommand>(shopSystem);
            }
            else if (commandName == "view-bought")
            {
                command = make_unique<ViewBoughtCommand>(shopSystem);
            }
            else if (commandName == "view-purchases")
            {
                command = make_unique<ViewPurchasesCommand>(shopSystem);
            }
            else if (commandName == "cancel-purchase")
            {
                unsigned pId;
                cin >> pId;
                command = make_unique<CancelPurchaseCommand>(shopSystem, pId);
            }
            else if (commandName == "recommend")
            {
                command = make_unique<RecommendCommand>(shopSystem);
            }
            else if (commandName == "make-review")
            {
                string name, comment;
                unsigned rating;
                cin >> name >> rating;

                getline(cin >> ws, comment);

                command = make_unique<MakeReviewCommand>(shopSystem, name, rating, comment);
            }

            else if (commandName == "create-fragrance")
            {
                string name, brand, family;
                double price;
                cin >> name >> brand >> price >> family;
                command = make_unique<CreateFragranceCommand>(shopSystem, name, brand, price, family);
            }
            else if (commandName == "add-quantity")
            {
                string name;
                int qty;
                cin >> name >> qty;
                command = make_unique<AddQuantityCommand>(shopSystem, name, qty);
            }
            else if (commandName == "deliver")
            {
                int pId;
                cin >> pId;
                command = make_unique<DeliverCommand>(shopSystem, pId);
            }
            else if (commandName == "remove-review")
            {
                int fId, rId;
                cin >> fId >> rId;
                command = make_unique<RemoveReviewCommand>(shopSystem, fId, rId);
            }
            else if (commandName == "block-user")
            {
                string username;
                cin >> username;
                command = make_unique<BlockUserCommand>(shopSystem, username);
            }
            else if (commandName == "add-to-wishlist")
            {
                string fragranceName;
                cin >> fragranceName;
                command = make_unique<AddToWishlistCommand>(shopSystem, fragranceName);
                }
            else if (commandName == "remove-from-wishlist")
            {
                string fragranceName;
                cin >> fragranceName;
                command = make_unique<RemoveFromWishlistCommand>(shopSystem, fragranceName);
                }
            else
            {
                cout << "Грешка: Непозната команда!\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (command != nullptr)
            {
                command->execute();
            }
        }
        catch (const std::exception& e)
        {
            cout << "--- ВЪЗНИКНА ГРЕШКА: " << e.what() << " ---\n";
        }
    }

    return 0;
}