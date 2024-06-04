#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>


static void print_element_names(xmlNode *a_node) {
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("node type: Element, name: %s\n", cur_node->name);
            if (cur_node->properties != NULL) {
                xmlAttr *cur_node_pr= cur_node->properties;
                for (cur_node_pr; cur_node_pr; cur_node_pr = cur_node_pr->next) {
                    printf("\tnode type: %s: %s\n", cur_node_pr->name, cur_node_pr->children->content);
                }
            }
        }
        print_element_names(cur_node->children);
    }
}

int main(int argc, char **argv) {
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;


    doc = xmlReadFile("D:/Projects/c_xml/simple.xml", NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", argv[1]);
    }

    root_element = xmlDocGetRootElement(doc);

    print_element_names(root_element);

    xmlFreeDoc(doc);

    xmlCleanupParser();

    return 0;
}