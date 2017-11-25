#ifndef WITTYHELLOWORLD_HELLOWORLD_HPP
#define WITTYHELLOWORLD_HELLOWORLD_HPP

#include <Wt/WApplication.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>

class HelloWorldApplication: public Wt::WApplication {
public:
    explicit HelloWorldApplication(const Wt::WEnvironment &environment);
private:
    Wt::WLineEdit *nameEdit;
    Wt::WText *greeting;

    void greet();
};


#endif //WITTYHELLOWORLD_HELLOWORLD_HPP
