#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBreak.h>
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include "include/HelloWorldApplication.hpp"


HelloWorldApplication::HelloWorldApplication(
        const Wt::WEnvironment &environment)
    :Wt::WApplication(environment)
{
    setTitle("Hello world");
    Wt::WContainerWidget* rootWidget = root();

    rootWidget->addWidget(std::make_unique<Wt::WText>("Your name please? "));
    nameEdit = rootWidget->addWidget(std::make_unique<Wt::WLineEdit>());
    nameEdit->setFocus(true);
    nameEdit->enterPressed().connect(this, &HelloWorldApplication::greet);

    auto button = rootWidget->addWidget(std::make_unique<Wt::WPushButton>("Greet me."));
    button->setMargin(5, Wt::Side::Left);
    button->clicked().connect(this, &HelloWorldApplication::greet);

    rootWidget->addWidget(std::make_unique<Wt::WBreak>());

    greeting = rootWidget->addWidget(std::make_unique<Wt::WText>());

    button->clicked().connect([=]() {
        std::cerr << "Hello there, " << nameEdit->text() << std::endl;
    });
}

void HelloWorldApplication::greet() {
    greeting->setText("Hello there, " + nameEdit->text());
}
