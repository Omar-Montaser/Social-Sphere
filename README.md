# Social-Sphere

Social-Sphere is a C++ application that models a social network and provides users with common social networking features, including **friend recommendations** and a visual representation of their social sphere. The project uses graph traversal, metadata prioritization, and Graphviz for visualization.

## Features

1. **User Account System**:
   - **Sign Up**: Users can register by creating a new account.
   - **Log In**: Users can log in to manage their social connections.
   
2. **Friendship Management**:
   - **View Friends**: Lists all current friends with an option to remove any.
   - **Add Friends**: Add friends by entering their usernames.

3. **Friend Recommendations**:
   - Suggestions are based on:
     - **Depth**: The closeness of a connection (friends-of-friends are prioritized over distant connections).
     - **Frequency**: Number of mutual friends (considered for connections at depth 2).
   - Recommendations are ranked using a **priority queue** to provide the most relevant connections.

4. **Social Sphere Visualization**:
   - Displays the social network as a graph using **Graphviz**.
   - **Nodes** represent usernames, and **edges** represent friendships.

---

## How Friend Recommendations Work

1. The adjacency list of a user's connections is traversed.
2. Metadata is collected for each potential connection:
   - **Depth**: Indicates the level of friendship (direct friends, mutual friends, etc.).
   - **Frequency**: The number of mutual friends (used for depth 2 connections).
3. A **priority queue** is used to rank potential friends:
   - Priority is given to lower depths (closer connections).
   - Frequency (number of mutual friends) is considered at depth 2.
4. The result is an array of recommended user IDs, which is mapped to usernames using the database:
   ```cpp
   database[userID] = username;
