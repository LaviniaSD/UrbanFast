// Class Saller

#ifndef SALLER_H
#define SALLER_H

class Saller {
    private:
        int iSallerID;
        int iItems;
        int iQuantity;
        int SallerLocation;

    public:
        Saller(int iSallerID, int iItems, int SallerLocation);

        void setSallerID(int iSallerID);
        int getSallerID();

        void setItems(int iItems);
        int getItems();

        void setQuantity(int iQuantity);
        int getQuantity();

        void setSallerLocation(int SallerLocation);
        int getSallerLocation();

};


#endif
