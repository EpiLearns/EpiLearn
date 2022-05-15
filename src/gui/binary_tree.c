#include "binary_tree.h"

#define CHECK(pointer) \
        if(pointer == NULL) \
            return NULL;


void get_b_object()
{
    binary_treeWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.tools.binary_tree"));

    tool_b_insert_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_b_insert_entry"));
    tool_b_insert_left_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_insert_left_button"));
    tool_b_insert_right_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_insert_right_button"));

    tool_b_left_del_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_left_del_button"));
    tool_b_right_del_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_right_del_button"));

    tool_b_clear_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_clear_button"));

    tool_b_left_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_left_button"));
    tool_b_right_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_right_button"));

    tool_b_root_button =GTK_BUTTON(gtk_builder_get_object(builder, "tool_b_root_button"));

    tool_b_key_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_b_key_text"));

    bt1 = GTK_WIDGET(gtk_builder_get_object(builder, "bt1"));
    bt2 = GTK_WIDGET(gtk_builder_get_object(builder, "bt2"));
    bt3 = GTK_WIDGET(gtk_builder_get_object(builder, "bt3"));
    bt4 = GTK_WIDGET(gtk_builder_get_object(builder, "bt4"));
    bt5 = GTK_WIDGET(gtk_builder_get_object(builder, "bt5"));
    bt6 = GTK_WIDGET(gtk_builder_get_object(builder, "bt6"));
    bt7 = GTK_WIDGET(gtk_builder_get_object(builder, "bt7"));
    bt8 = GTK_WIDGET(gtk_builder_get_object(builder, "bt8"));
    bt9 = GTK_WIDGET(gtk_builder_get_object(builder, "bt9"));
    bt10 = GTK_WIDGET(gtk_builder_get_object(builder, "bt10"));
    bt11 = GTK_WIDGET(gtk_builder_get_object(builder, "bt11"));
    bt12 = GTK_WIDGET(gtk_builder_get_object(builder, "bt12"));
    bt13 = GTK_WIDGET(gtk_builder_get_object(builder, "bt13"));
    bt14 = GTK_WIDGET(gtk_builder_get_object(builder, "bt14"));
    bt15 = GTK_WIDGET(gtk_builder_get_object(builder, "bt15"));
    bt16 = GTK_WIDGET(gtk_builder_get_object(builder, "bt16"));
    bt17 = GTK_WIDGET(gtk_builder_get_object(builder, "bt17"));
    bt18 = GTK_WIDGET(gtk_builder_get_object(builder, "bt18"));
    bt19 = GTK_WIDGET(gtk_builder_get_object(builder, "bt19"));
    bt20 = GTK_WIDGET(gtk_builder_get_object(builder, "bt20"));
    bt21 = GTK_WIDGET(gtk_builder_get_object(builder, "bt21"));
    bt22 = GTK_WIDGET(gtk_builder_get_object(builder, "bt22"));
    bt23 = GTK_WIDGET(gtk_builder_get_object(builder, "bt23"));
    bt24 = GTK_WIDGET(gtk_builder_get_object(builder, "bt24")); 
    bt25 = GTK_WIDGET(gtk_builder_get_object(builder, "bt25"));
    bt26 = GTK_WIDGET(gtk_builder_get_object(builder, "bt26"));
    bt27 = GTK_WIDGET(gtk_builder_get_object(builder, "bt27"));
    bt28 = GTK_WIDGET(gtk_builder_get_object(builder, "bt28"));
    bt29 = GTK_WIDGET(gtk_builder_get_object(builder, "bt29"));
    bt30 = GTK_WIDGET(gtk_builder_get_object(builder, "bt30"));
    bt31 = GTK_WIDGET(gtk_builder_get_object(builder, "bt31"));
}

void bt_insert_left_ui(GtkButton* b, gpointer user)
{   
    Nodes* tmp = user;

    if (!rootTree)
    {
        const gchar* key = gtk_entry_get_text(GTK_ENTRY(tool_b_insert_entry));
        rootTree = init_binary_tree(atoi(key));
        rootTree->order = 1;
        currentTree = rootTree;

        char buff[32];
        sprintf(buff,"B.key = %i",currentTree->key);
        
        gtk_label_set_text(GTK_LABEL(tool_b_key_text),buff);
        gtk_entry_set_text(GTK_ENTRY(tool_b_insert_entry),"");

        char buff2 [32];
        sprintf(buff2,"%i\n/  \\",currentTree->key);

        gtk_label_set_text(GTK_LABEL(tmp->bt),buff2);
    }

    else if (!currentTree->left && currentTree->order*2 < 32)
    {
        const gchar* key = gtk_entry_get_text(GTK_ENTRY(tool_b_insert_entry));
        bt_insert_left(currentTree,atoi(key));
        gtk_entry_set_text(GTK_ENTRY(tool_b_insert_entry),"");

        for (int i = currentTree->left->order;i > 1; i--)
        {
            tmp = tmp->next;
        }

        char buff2 [32];
        sprintf(buff2,"%i\n/  \\",currentTree->left->key);

        gtk_label_set_text(GTK_LABEL(tmp->bt),buff2);
    }

    useless_button4 = b;
}

void bt_insert_right_ui(GtkButton* b, gpointer user)
{
    Nodes* tmp = user;

    if (!rootTree)
    {
        const gchar* key = gtk_entry_get_text(GTK_ENTRY(tool_b_insert_entry));
        rootTree = init_binary_tree(atoi(key));
        rootTree->order = 1;
        currentTree = rootTree;

        char buff[32];
        sprintf(buff,"B.key = %i",currentTree->key);

        gtk_label_set_text(GTK_LABEL(tool_b_key_text),buff);
        gtk_entry_set_text(GTK_ENTRY(tool_b_insert_entry),"");

        char buff2 [32];
        sprintf(buff2,"%i\n/  \\",currentTree->key);

        gtk_label_set_text(GTK_LABEL(tmp->bt),buff2);
    }

    else if (!currentTree->right && currentTree->order*2 + 1 < 32)
    {
        const gchar* key = gtk_entry_get_text(GTK_ENTRY(tool_b_insert_entry));
        bt_insert_right(currentTree,atoi(key));
        gtk_entry_set_text(GTK_ENTRY(tool_b_insert_entry),"");

        for (int i = currentTree->right->order;i > 1; i--)
        {
            tmp = tmp->next;
        }

        char buff2 [32];
        sprintf(buff2,"%i\n/  \\",currentTree->right->key);

        gtk_label_set_text(GTK_LABEL(tmp->bt),buff2);
    }

    useless_button4 = b;
}

void bt_go_left_ui()
{
    if (currentTree)
    {
        if (currentTree->left)
        {
            currentTree = currentTree->left;
            char buff [32];
            sprintf(buff,"B.key = %i",currentTree->key);

            gtk_label_set_text(GTK_LABEL(tool_b_key_text),buff);
        }
    }
}

void bt_go_right_ui()
{
    if (currentTree)
    {
        if (currentTree->right)
        {
            currentTree = currentTree->right;
            char buff [32];
            sprintf(buff,"B.key = %i",currentTree->key);

            gtk_label_set_text(GTK_LABEL(tool_b_key_text),buff);
        }
    }
}

void bt_clear_ui(GtkButton* b,gpointer user)
{
    bt_free(rootTree);
    rootTree = NULL;
    currentTree = NULL;

    gtk_label_set_text(GTK_LABEL(tool_b_key_text),"B.key = None");

    Nodes* tmp = user;

    while (tmp)
    {
        gtk_label_set_text(GTK_LABEL(tmp->bt),"");
        tmp = tmp->next;
    }

    useless_button4 = b;
}

void bt_go_root()
{
    if (currentTree)
    {
        currentTree = rootTree;
        char buff [32];
        sprintf(buff,"B.key = %i",currentTree->key);

        gtk_label_set_text(GTK_LABEL(tool_b_key_text),buff);
    }
}

void bt_del_left(GtkButton* b, gpointer user)
{
    Nodes* tmp = user;

    if (currentTree)
    {
        if (currentTree->left && !currentTree->left->left && !currentTree->left->right)
        {
            for (int i = currentTree->left->order;i > 1; i--)
            {
                tmp = tmp->next;
            }

            gtk_label_set_text(GTK_LABEL(tmp->bt),"");

            BinaryTree* elt = currentTree->left;
            currentTree->left = NULL;

            free(elt);
        }
    }

    useless_button4 = b;
}

void bt_del_right(GtkButton* b, gpointer user)
{
    Nodes* tmp = user;

    if (currentTree)
    {
        if (currentTree->right && !currentTree->right->left && !currentTree->right->right)
        {
            for (int i = currentTree->right->order;i > 1; i--)
            {
                tmp = tmp->next;
            }

            gtk_label_set_text(GTK_LABEL(tmp->bt),"");

            BinaryTree* elt = currentTree->right;
            currentTree->right = NULL;

            free(elt);
        }
    }

    useless_button4 = b;
}

void b_signal()
{
    rootTree = NULL;
    currentTree = NULL;

    g_signal_connect(tool_b_root_button,"clicked",G_CALLBACK(bt_go_root),NULL);

    g_signal_connect(tool_b_left_button,"clicked",G_CALLBACK(bt_go_left_ui),NULL);
    g_signal_connect(tool_b_right_button,"clicked",G_CALLBACK(bt_go_right_ui),NULL);

    g_signal_connect(tool_b_clear_button,"clicked",G_CALLBACK(bt_clear_ui),bt_nodes);

    g_signal_connect(tool_b_insert_left_button,"clicked",G_CALLBACK(bt_insert_left_ui),bt_nodes);
    g_signal_connect(tool_b_insert_right_button,"clicked",G_CALLBACK(bt_insert_right_ui),bt_nodes);

    g_signal_connect(tool_b_left_del_button,"clicked",G_CALLBACK(bt_del_left),bt_nodes);
    g_signal_connect(tool_b_right_del_button,"clicked",G_CALLBACK(bt_del_right),bt_nodes);
}

void open_binary_tree_fct()
{
    gtk_init(NULL, NULL);
    builder = gtk_builder_new ();
    GError* error = NULL;

    if (gtk_builder_add_from_file(builder, "../res/binary_tree.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    get_b_object();

    bt_nodes = calloc(1,sizeof(Nodes));
    Nodes* tmp = bt_nodes;

    tmp->bt = bt1;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt2;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt3;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt4;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt5;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt6;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt7;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt8;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt9;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt10;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt11;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt12;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt13;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt14;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt15;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt16;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt17;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt18;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt19;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt20;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt21;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt22;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt23;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt24;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt25;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt26;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt27;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt28;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt29;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt30;
    tmp->next = calloc(1,sizeof(Nodes));
    tmp = tmp->next;

    tmp->bt = bt31;

    b_signal();

    // Connects event handlers.
    g_signal_connect(binary_treeWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(GTK_WIDGET(binary_treeWindow));
    // Run the main window.
    gtk_main();
}