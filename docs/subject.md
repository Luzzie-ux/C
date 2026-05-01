# Linked Lists
 
Memory and string manipulation functions are useful. But you will soon discover that manipulating lists is even more useful.
 
In this third part, you have to implement functions using a structure to manipulate linked list. To do so, add the following structure declaration to your `libft.h` file:
 
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```
 
The members of the `t_list` struct are:
 
- **`content`**: The data contained in the node. Using `void *` allows you to store any type of data.
- **`next`**: The address of the next node, or `NULL` if the current node is the last one.
Implement the following functions in order to easily use your lists:
 
---
 
## ft_lstnew
 
| | |
|---|---|
| **Prototype** | `t_list *ft_lstnew(void *content);` |
| **Parameters** | `content` — The content to store in the new node. |
| **Return Value** | A pointer to the new node. |
| **External Function** | `malloc` |
 
**Description:** Allocates memory (using `malloc(3)`) and returns a new node. The `content` member variable is initialized with the given parameter `content`. The variable `next` is initialized to `NULL`.
 
---
 
## ft_lstadd_front
 
| | |
|---|---|
| **Prototype** | `void ft_lstadd_front(t_list **lst, t_list *new);` |
| **Parameters** | `lst` — The address of a pointer to the first node of a list. `new` — The address of a pointer to the node to be added. |
| **Return Value** | None |
| **External Function** | None |
 
**Description:** Adds the node `new` at the beginning of the list.
 
---
 
## ft_lstsize
 
| | |
|---|---|
| **Prototype** | `int ft_lstsize(t_list *lst);` |
| **Parameters** | `lst` — The beginning of the list. |
| **Return Value** | The length of the list. |
| **External Function** | None |
 
**Description:** Counts the number of nodes in the list.
 
---
 
## ft_lstlast
 
| | |
|---|---|
| **Prototype** | `t_list *ft_lstlast(t_list *lst);` |
| **Parameters** | `lst` — The beginning of the list. |
| **Return Value** | Last node of the list. |
| **External Function** | None |
 
**Description:** Returns the last node of the list.
 
---
 
## ft_lstadd_back
 
| | |
|---|---|
| **Prototype** | `void ft_lstadd_back(t_list **lst, t_list *new);` |
| **Parameters** | `lst` — The address of a pointer to the first node of a list. `new` — The address of a pointer to the node to be added. |
| **Return Value** | None |
| **External Function** | None |
 
**Description:** Adds the node `new` at the end of the list.
 
---
 
## ft_lstdelone
 
| | |
|---|---|
| **Prototype** | `void ft_lstdelone(t_list *lst, void (*del)(void *));` |
| **Parameters** | `lst` — The node to free. `del` — The address of the function used to delete the content. |
| **Return Value** | None |
| **External Function** | `free` |
 
**Description:** Takes a node as parameter and frees its content using the function `del`. Frees the node itself but does **NOT** free the next node.
 
---
 
## ft_lstclear
 
| | |
|---|---|
| **Prototype** | `void ft_lstclear(t_list **lst, void (*del)(void *));` |
| **Parameters** | `lst` — The address of a pointer to a node. `del` — The address of the function used to delete the content of the node. |
| **Return Value** | None |
| **External Function** | `free` |
 
**Description:** Deletes and frees the given node and all its successors, using the function `del` and `free(3)`. Finally, sets the pointer to the list to `NULL`.
 
---
 
## ft_lstiter
 
| | |
|---|---|
| **Prototype** | `void ft_lstiter(t_list *lst, void (*f)(void *));` |
| **Parameters** | `lst` — The address of a pointer to a node. `f` — The address of the function to apply to each node's content. |
| **Return Value** | None |
| **External Function** | None |
 
**Description:** Iterates through the list `lst` and applies the function `f` to the content of each node.
 
---
 
## ft_lstmap
 
| | |
|---|---|
| **Prototype** | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` |
| **Parameters** | `lst` — The address of a pointer to a node. `f` — The address of the function applied to each node's content. `del` — The address of the function used to delete a node's content if needed. |
| **Return Value** | The new list, or `NULL` if the allocation fails. |
| **External Function** | `malloc`, `free` |
 
**Description:** Iterates through the list `lst`, applies the function `f` to each node's content, and creates a new list resulting from the successive applications of the function `f`. The `del` function is used to delete the content of a node if needed.
 
