const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="preconnect" href="https://fonts.gstatic.com">
	<link href="https://fonts.googleapis.com/css2?family=Bebas+Neue&display=swap" rel="stylesheet">
	<title>Tobagi</title>
	<style>
		html, body {
			margin: 0;
			height: 100%;
			width: 100%;
		}

		body {
			font-family: "Bebas Neue", sans-serif;
			background-color: #1c1c1c;
			background-size: cover;
			background-position: top;
			background-repeat: no-repeat;
			color: white;
		}

		h1 {
			line-height: 1;
			margin: 0;
			font-size: 5rem;
			position: absolute;
			bottom: 1rem;
			left: 1rem;
			mix-blend-mode: difference;
		}

		.open {
			background-image: url("https://media.giphy.com/media/GeimqsH0TLDt4tScGw/giphy.gif");
		}

		.closed {
			background-image: url("https://media.giphy.com/media/9G3wg7lH5DpxC/giphy.gif");
		}

		.open span {
			color: green;
		}

		.open span::after {
			content: "open";
		}

		.closed span {
			color: red;
		}

		.closed span::after {
			content: "closed";
		}
	</style>
</head>
<body class="%s">
	<h1>Tobagi is <span></span></h1>
</body>
</html>)rawliteral";

