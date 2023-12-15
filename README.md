<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Solaar7/APC-Injection">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">APC-Injection</h3>

  <p align="center">
    A simple Windows malware application that utilizes NTAPI, Indirect Syscalls, and APC queues to execute m
    <br />
    <a href="https://github.com/Solaar7/APC-Injection"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Solaar7/APC-Injection/issues">Report Bug</a>
    ·
    <a href="https://github.com/Solaar7/APC-Injection/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

# DISCLAIMER: PLEASE DO NOT ATTEMPT TO ATTACK ANY SYSTEMS WITHOUT THE OWNERS EXPLICIT PERMISSION

I've been exploring malware development and other offensive security concepts. This repository exhibits one method of executing code via Process Injection. Remember that there is no single way to evade an antivirus; all "successful" malware applications combine different techniques. 
<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* Cmake:[cmake-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

Running this should be quite simple. You will have to edit the main.c file and adjust the DLL path variable to the location of the evil DLL.

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Solaar7/APC-Injection.git
   ```
2. Change the path variable in the code to your DLL's path
3. Install CMake from the [official site][cmake-url]
4. Use the following command to compile the program
   ```pwsh
   cmake --build build
   ```
5. Finally, open a Notepad process and run the file

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

This program is just one example of how APC queries can be leveraged to gain control or escalate priveleges on a system. To run this application, build it using the steps above and open a Notepad window. That is what the program will inject code into. finally, you can run the file with the following command:
'''pwsh
.\path\to\file\APC-Injection.exe
'''
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## Disclaimer

Please do not attempt to attack any system or network unless you have EXPLICIT permission. I take no responsibility
for any damage caused by my programs.

<!-- CONTACT -->
## Contact

Project Link: [https://github.com/Solaar7/APC-Injection](https://github.com/Solaar7/APC-Injection)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Crow](https://www.crow.rip/crows-nest/general/whoami)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Solaar7/APC-Injection.svg?style=for-the-badge
[contributors-url]: https://github.com/Solaar7/APC-Injection/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Solaar7/APC-Injection.svg?style=for-the-badge
[forks-url]: https://github.com/Solaar7/APC-Injection/network/members
[stars-shield]: https://img.shields.io/github/stars/Solaar7/APC-Injection.svg?style=for-the-badge
[stars-url]: https://github.com/Solaar7/APC-Injection/stargazers
[issues-shield]: https://img.shields.io/github/issues/Solaar7/APC-Injection.svg?style=for-the-badge
[issues-url]: https://github.com/Solaar7/APC-Injection/issues
[license-shield]: https://img.shields.io/github/license/Solaar7/APC-Injection.svg?style=for-the-badge
[license-url]: https://github.com/Solaar7/APC-Injection/blob/master/LICENSE.txt
[cmake-url]: https://cmake.org/
