		{
			token = strtok(lineptr, delim); /* split strings into words */
			while (token != NULL)
			{
				token_args[i] = token; /* token arguments */
				i++;
				token = strtok(NULL, delim); /* second string */
			}
			token_args[i] = NULL; /* add null character to end of argument */
		}

