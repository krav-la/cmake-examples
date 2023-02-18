#include "MainWindow.h"

MainWindow::MainWindow() : button("Show"), infoLabel(tr("Simple GUI app"))
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    infoLabel.setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel.setAlignment(Qt::AlignCenter);
    infoLabel.setVisible(false);
    layout.setContentsMargins(5, 5, 5, 5);
    layout.addWidget(&infoLabel);
    layout.addWidget(&button);
    widget->setLayout(&layout);

    setWindowTitle(tr("Example GUI app"));
    setMinimumSize(160, 160);
    resize(480, 320);

    connect(&button, &QPushButton::clicked, this, &MainWindow::onShowClicked);
}

void MainWindow::onShowClicked(bool val)
{
    if (button.text() == "Show")
    {
        button.setText("Hide");
        infoLabel.setVisible(true);
    }
    else
    {
        button.setText("Show");
        infoLabel.setVisible(false);
    }
}