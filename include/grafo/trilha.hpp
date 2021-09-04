#ifndef TRILHA
#define TRILHA

namespace grafo {
    class Trilha {
        private:
            int u;
            int v;

        public:
            Trilha();
            Trilha(int u, int v);

            int getU();
            int getV();

            void setU(int u);
            void setV(int v);
    };

}

#endif