while (parent != 'A') {
            path += parent;
            int index = find(all(direction), parent) - direction.begin();
            i -= dy[index];
            j -= dx[index];
            parent = previous[i][j];
        }