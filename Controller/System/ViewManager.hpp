#ifndef CONTROLLERS_VIEW_MANAGER_HPP
#define CONTROLLERS_VIEW_MANAGER_HPP

#include "../../Model/Enum/EnumViewTag.hpp"
#include "../../View/View.hpp"

namespace systems {
    using namespace models;
    using namespace views;
    
    class ViewManager {
        private:
            std::unordered_map<ViewTag, View*> mapView;
            int nScreenRows = 2;
            int nScreenCols = 2;


        public:
            void registerView(View* pView);
            void unregisterView(View* pView);
        
        public:
            View* getView(ViewTag ETag);
            int getScreenRows();
            int getScreenCols();
            void incrementRows();
            void incrementCols();

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static ViewManager* P_SHARED_INSTANCE;

        private:
            ViewManager();
            ViewManager(const ViewManager&);
            ViewManager& operator = (const ViewManager&);

        public:
            static ViewManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif