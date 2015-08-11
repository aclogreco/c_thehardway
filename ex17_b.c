#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Constants that set maximum size of the database and data elements.  */
#define MAX_ROWS 100
#define MAX_DATA 512


struct Address {
  int id;
  int set;
  /*
  char name[MAX_DATA];
  char email[MAX_DATA];
  */
  char *name;
  char *email;
};

struct Database {
  int num_rows;
  int data_size;
  /*struct Address rows[MAX_ROWS];*/
  struct Address *rows;
};

struct Connection {
  FILE *file;
  struct Database *db;
};


/* Define the Database_close prototype here so that the die function can 
   call it.  */
void Database_close(struct Connection*);


/* This function prints an error message, closes the database file and exits 
   the program.  */
void die(const char *message, struct Connection *conn) {
  if (errno) {
    perror(message);
  }
  else {
    printf("ERROR: %s\n", message);
  }
  
  Database_close(conn);
  
  exit(1);
}


/* This function prints a record to standard output.  */
void Address_print(struct Address *addr) {
  printf("%d %s %s\n",
	 addr->id, addr->name, addr->email);
}


/* This function loads the database by reading it from the file specified in 
   the Connection structure.  */
void Database_load(struct Connection *conn) {
  /*
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) {
    die("Failed to load database.", conn);
  }
  */
  /* Read the database, piece by piece, from the file specified by 
     conn->file.  */
  int rc = fread(&(conn->db->num_rows), sizeof(conn->db->num_rows), 1, 
		  conn->file);
  if (rc != 1) {
    die("Failed to load database.", conn);
  }
  
  rc = fread(&(conn->db->data_size), sizeof(conn->db->data_size), 1, 
	      conn->file);
  if (rc != 1) {
    die("Failed to load database.", conn);
  }
  
  conn->db->rows = calloc(conn->db->num_rows, sizeof(struct Address));
  if (!conn->db->rows) {
    die("Memory error.", conn);
  }
  /*
  rc = fread(conn->db->rows, sizeof(struct Address), conn->db->num_rows, 
	      conn->file);
  if (rc != conn->db->num_rows) {
    die("Failed to load database.", conn);
  }
  */
  int i = 0;
  for (i = 0; i < conn->db->num_rows; i++) {
    struct Address addr;
    
    rc = fread(&(addr.id), sizeof(addr.id), 1, conn->file);
    if (rc != 1) {
      die("Failed to load database.", conn);
    }
    
    rc = fread(&(addr.set), sizeof(addr.set), 1, conn->file);
    if (rc != 1) {
      die("Failed to load database.", conn);
    }
    
    addr.name = calloc(conn->db->data_size, sizeof(char));
    if (!addr.name) {
      die("Memory error.", conn);
    }
    rc = fread(addr.name, sizeof(char), conn->db->data_size, conn->file);
    if (rc != conn->db->data_size) {
      die("Failed to load database.", conn);
    }
    
    addr.email = calloc(conn->db->data_size, sizeof(char));
    if (!addr.email) {
      die("Memory error.", conn);
    }
    rc = fread(addr.email, sizeof(char), conn->db->data_size, conn->file);
    if (rc != conn->db->data_size) {
      die("Failed to load database.", conn);
    }
    
    conn->db->rows[i] = addr;
  }
}


/* This function opens the file that the database is stored and creates 
   a connection to it.  */
struct Connection *Database_open(const char *filename, char mode) {
  /* Allocate memmory for Connection structure.  */
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn) {
    die("Memory error", conn);
  }
  
  /* Allocate memory for db component of conn.  */
  conn->db = malloc(sizeof(struct Database));
  if (!conn->db) {
    die("Memory error", conn);
  }
  
  if (mode == 'c') {
    /* When in create mode, open the file for writing. If the file exists, it 
       will be erased. If the file does not exist, it will be created. In both 
       instances, the file position will be set to the begining of the file.  */
    conn->file = fopen(filename, "w");
  }
  else {
    /* For all other modes, open the file for reading and writing. The file 
       position will set to the begining of the file.  */
    conn->file = fopen(filename, "r+");
    
    if (conn->file) {
      /* Load the database from the file since it already exists.  */
      Database_load(conn);
    }
  }
  
  if (!conn->file) {
    die("Failed to open the file", conn);
  }
  
  return conn;
}


/* This function closes the database by closing the file and freeing the 
   memory that holds the data structures.  */
void Database_close(struct Connection *conn) {
  if (conn) {
    if (conn->file) {
      fclose(conn->file);
    }
    if (conn->db) {
      int i = 0;
      for (i = 0; i < conn->db->num_rows; i++) {
	free(conn->db->rows[i].name);
	free(conn->db->rows[i].email);
      }
      free(conn->db->rows);
      free(conn->db);
    }
    free(conn);
  }
}


/* This function writes the database out to a file.  */
void Database_write(struct Connection *conn) {
  /* Set the file position to the begining of the file.  */
  rewind(conn->file);
  
  /* Write the db component of conn to the file compnonent of conn.  */
  /*int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) {
    die("Failed to write database.", conn);
  }*/
  
  /* Write the database, piece by piece, to the file specified by 
     conn->file.  */
  int rc = fwrite(&(conn->db->num_rows), sizeof(conn->db->num_rows), 1, 
		  conn->file);
  if (rc != 1) {
    die("Failed to write NUM_ROWS component of database.", conn);
  }
  
  rc = fwrite(&(conn->db->data_size), sizeof(conn->db->data_size), 1, 
	      conn->file);
  if (rc != 1) {
    die("Failed to write DATA_SIZE component of database.", conn);
  }
  
  /*
  rc = fwrite(conn->db->rows, sizeof(struct Address), conn->db->num_rows, 
	      conn->file);
  if (rc != conn->db->num_rows) {
    die("Failed to write ROWS component of database.", conn);
  }
  */
  int i = 0;
  for (i = 0; i < conn->db->num_rows; i++) {
    struct Address *addr = &conn->db->rows[i];
    rc = fwrite(&(addr->id), sizeof(addr->id), 1, conn->file);
    if (rc != 1) {
      die("Failed to write ID component of address record.", conn);
    }
    
    rc = fwrite(&(addr->set), sizeof(addr->set), 1, conn->file);
    if (rc != 1) {
      die("Failed to write SET component of address record.", conn);
    }
    
    rc = fwrite(addr->name, sizeof(char), conn->db->data_size, conn->file);
    if (rc != conn->db->data_size) {
      die("Failed to write NAME component of address record.", conn);
    }
    
    rc = fwrite(addr->email, sizeof(char), conn->db->data_size, conn->file);
    if (rc != conn->db->data_size) {
      die("Failed to write EMAIL component of address record.", conn);
    }
  }
  
  /* Flush the stream buffer to make sure that the data is written to the 
     file and not still held in memory.  */
  rc = fflush(conn->file);
  if (rc == -1) {
    die("Can not flush database.", conn);
  }
}


/* This function creates and initializes an empty database.  */
void Database_create(struct Connection *conn, int num_rows, int data_size) {
  /* Set the nuber of records in the database and the size of the string 
     components of the records.  */
  conn->db->num_rows = num_rows;
  conn->db->data_size = data_size;
  
  /* Allocate memory to store array of struct Address records.  */
  conn->db->rows = calloc(conn->db->num_rows, sizeof(struct Address));
  if (!conn->db->rows) {
    die("Memory error.", conn);
  }
  
  int i = 0;
  for (i = 0; i < conn->db->num_rows; i++) {
    // make a prototype to initialize it
    struct Address addr = 
      {
	.id = i, 
	.set = 0, 
	.name = calloc(conn->db->data_size, sizeof(char)),
	.email = calloc(conn->db->data_size, sizeof(char))
      };
    if (!addr.name || !addr.email) {
      die("Memory error.", conn);
    }
    // then just assign it
    conn->db->rows[i] = addr;
  }
}


/* This function sets the record specified by id.  */
void Database_set(struct Connection *conn, int id, 
		  const char *name, const char *email) {
  struct Address *addr = &conn->db->rows[id];
  if (addr->set) {
    die("Already set, delete it first", conn);
  }
  
  addr->set = 1;
  char *res = strncpy(addr->name, name, conn->db->data_size);
  addr->name[(conn->db->data_size)-1] = '\0';
  if (!res) {
    die("Name copy failed", conn);
  }
  
  res = strncpy(addr->email, email, conn->db->data_size);
  addr->email[(conn->db->data_size)-1] = '\0';
  if (!res) {
    die("Email copy failed", conn);
  }
}


/* This function gets and prints to standard output the record specified by 
   id.  */
void Database_get(struct Connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id];
  
  if (addr->set) {
    Address_print(addr);
  }
  else {
    die("ID is not set", conn);
  }
}


/* This function deletes the record specified by id.  */
void Database_delete(struct Connection *conn, int id) {
  struct Address addr = {
    .id = id, 
    .set = 0,
    .name = calloc(conn->db->data_size, sizeof(char)),
    .email = calloc(conn->db->data_size, sizeof(char))
  };
  conn->db->rows[id] = addr;
}


/* This function prints to standard output all th records that have been 
   set.  */
void Database_list(struct Connection *conn) {
  int i = 0;
  struct Database *db = conn->db;
  
  for (i = 0; i < conn->db->num_rows; i++) {
    struct Address *cur = &db->rows[i];
    
    if (cur->set) {
      Address_print(cur);
    }
  }
}


int main(int argc, char *argv[]) {
  if (argc < 3) {
    die("USAGE: ex17 <dbfile> <action> [action params]", NULL);
  }
  
  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);
  int id = 0;
  int num_rows = 0;
  int data_size = 0;
  
  if (action == 'c') {
    if (argc > 4) {
      num_rows = atoi(argv[3]);
      data_size = atoi(argv[4]);
    }
    if (num_rows < 0 || data_size < 0) {
      die("The database size parameters need to be positive numbers.", conn);
    }
    if (num_rows == 0 || data_size == 0) {
      die("The database size parameters need to be greater than 0.", conn);
    }
    if (num_rows > MAX_ROWS) {
      die("The NUMBER OF ROWS given is greater than the maximum allowed.", conn);
    }
    if (data_size > MAX_DATA) {
      die("The DATA SIZE given is greater than the maximum allowed.", conn);
    }
  }
  else {
    if (argc > 3) {
      id = atoi(argv[3]);
    }
    if (id < 0) {
      die("ID needs to be a positive number.", conn);
    }
    if (id >= MAX_ROWS) {
      die("There's not that many records.", conn);
    }
  }
  
  switch (action) {
  case 'c':
    if (argc != 5) {
      die("Need to specify the NUMBER OF ROWS and DATA SIZE to create", conn);
    }
    /*conn->db->num_rows = num_rows;
      conn->db->data_size = data_size;*/
    Database_create(conn, num_rows, data_size);
    Database_write(conn);
    break;
    
  case 'g':
    if (argc != 4) {
      die("Need an ID to get", conn);
    }
    
    Database_get(conn, id);
    break;
    
  case 's':
    if (argc != 6) {
      die("Need ID, name, email to set", conn);
    }
    if (strlen(argv[4]) >= ((conn->db->data_size)-1)) {
      die("Name is too long.", conn);
    }
    if (strlen(argv[5]) >= ((conn->db->data_size)-1)) {
      die("Email is too long.", conn);
    }
    
    Database_set(conn, id, argv[4], argv[5]);
    Database_write(conn);
    break;
    
  case 'd':
    if (argc != 4) {
      die("Need ID to delete", conn);
    }
    
    Database_delete(conn, id);
    Database_write(conn);
    break;
    
  case 'l':
    Database_list(conn);
    break;
    
  default:
    die("Invalid action, only: c=create, g=get, s=set, d=delete, l=list", conn);
  }
  
  Database_close(conn);
  
  return 0;
}
