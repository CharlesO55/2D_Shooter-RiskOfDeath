#ifndef SYSTEMS_OBJECT_POOL_MANAGER_HPP
#define SYSTEMS_OBJECT_POOL_MANAGER_HPP

#include "../../Model/Enum/EnumPoolTag.hpp"
#include "../Pooling/GameObjectPool.hpp"

namespace systems {
    using namespace models;
    
    class ObjectPoolManager {
        private:
            std::unordered_map<PoolTag, GameObjectPool*> mapObjectPool;

        public:
            void registerObjectPool(GameObjectPool* pPool);
            void unregisterObjectPool(GameObjectPool* pPool);
        
        public:
            GameObjectPool* getPool(PoolTag ETag);

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static ObjectPoolManager* P_SHARED_INSTANCE;

        private:
            ObjectPoolManager();
            ObjectPoolManager(const ObjectPoolManager&);
            ObjectPoolManager& operator = (const ObjectPoolManager&);

        public:
            static ObjectPoolManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif