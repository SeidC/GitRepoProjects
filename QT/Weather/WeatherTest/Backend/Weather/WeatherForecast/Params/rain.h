#ifndef RAIN_H
#define RAIN_H

#include <QObject>

class Rain : public QObject
{
    Q_OBJECT

public:
    Rain();

    float getRainQuantity() const;
    void setRainQuantity(float value);

    int getRainRisk() const;
    void setRainRisk(int value);

private:
    float rainQuantity;
    int rainRisk;
};

#endif // RAIN_H
