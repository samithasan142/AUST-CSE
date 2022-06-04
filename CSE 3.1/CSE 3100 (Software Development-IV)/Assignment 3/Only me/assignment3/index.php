<!DOCTYPE html>
<html>

<head>
    <title>Assignment 2</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100;200;300;400;500;600;700;800;900&display=swap" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script src="https://kit.fontawesome.com/a076d05399.js" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="css/main.css">
</head>

<body>
    <div class="container">
        <div class="row">
            <div class="col-md-6 image-container">
                <div class="subheading">
                    <span class="spacing"></span>
                    <span class="text-container">
                        <span class="left-bracket">[</span>
                        <span class="text">
                            CONTACT US
                        </span>
                        <span class="right-bracket">]</span>
                    </span>
                </div>
                <div class="heading">
                    Let's Get in Touch
                </div>
                <div class="icon-contain">
                    <div class="icon-holder">
                        <div class="icon">
                            <i class="fas fa-map-marker-alt"></i>
                        </div>
                        <div class="text">
                            <h3>Address</h3>
                            <p>12 Moda Center Street, Home<br />New York</p>
                        </div>
                    </div>
                    <div class="icon-holder">
                        <div class="icon">
                            <i class="fas fa-phone"></i>
                        </div>
                        <div class="text">
                            <h3>Phone</h3>
                            <p><a href="tel:+12345607890">+123 4560 7890</a></p>
                        </div>
                    </div>
                    <div class="icon-holder">
                        <div class="icon">
                            <i class="fas fa-envelope"></i>
                        </div>
                        <div class="text">
                            <h3>Email</h3>
                            <p><a href="mailto:123example@email.com">123example@email.com</a></p>
                        </div>
                    </div>
                </div>
                <form action="result.php" method="post" class="icon-button">
                    <input type="submit" class="button" value="See All Data" />
                </form>
            </div>
            <div class="col-md-6 form-container">
                <div class="message">
                    SEND MESSAGE
                </div>
                <form action="result.php" method="POST">
                    <div class="field name-container">
                        <label for="first-name">User Name<span class="required-mark">*</span></label>
                        <div class="field-name">
                            <input type="text" id="first-name" name="usernamefirst" value="" class="form-control first-name" placeholder="First Name" required />
                            <input type="text" id="last-name" name="usernamesecond" value="" class="form-control last-name" placeholder="Last Name" required />
                        </div>
                    </div>
                    <div class="field">
                        <label for="phone">Phone<span class="required-mark">*</span></label>
                        <input type="tel" id="phone" name="phone" value="" class="form-control" placeholder="Phone Number" required />
                    </div>
                    <div class="field">
                        <label for="email">Email<span class="required-mark">*</span></label>
                        <input type="text" id="email" name="email" value="" class="form-control" placeholder="Email Address" required />
                    </div>
                    <div class="field">
                        <label for="textarea">Message<span class="required-mark">*</span></label>
                        <textarea id="textarea" rows="5" class="form-control textarea" name="message" placeholder="Enter your message here..." required ></textarea>
                    </div>
                    <div class="field">
                        <input type="submit" class="button" value="Submit" />
                    </div>
                </form>
            </div>
        </div>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>